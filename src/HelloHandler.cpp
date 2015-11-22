#include "HelloHandler.h"


ns::HelloHandler::HelloHandler(fastcgi::ComponentContext *context) : fastcgi::Component(context), logger_(NULL) {
}

ns::HelloHandler::~HelloHandler() {
}

void ns::HelloHandler::handleRequest(fastcgi::Request *req, fastcgi::HandlerContext *handlerContext) {
	if(req->hasArg("a")) {
		std::cout << req->countArgs() << ":" << req->getArg("a") << std::endl;
	}

	std::cout << "QUERY_STRING=" << req->getQueryString() << std::endl;

	req->setContentType("text/plain");
	fastcgi::RequestStream stream(req);

	std::vector<std::string> names;
	req->argNames(names);
	for (std::vector<std::string>::iterator i = names.begin(), end = names.end(); i != end; ++i) {
		stream << "arg " << (*i) << " has value " << req->getArg(*i) << "\n";
	 }
	req->headerNames(names);
	for (std::vector<std::string>::iterator i = names.begin(), end = names.end(); i != end; ++i) {
		stream << "header " << (*i) << " has value " << req->getHeader(*i) << "\n";
	}
	req->cookieNames(names);
	for (std::vector<std::string>::iterator i = names.begin(), end = names.end(); i != end; ++i) {
		stream << "cookie " << (*i) << " has value " << req->getCookie(*i) << "\n";
	}

	stream << "test ok\n";

	logger_->info("request processed");

	req->setStatus(200);

	handlerContext->setParam("param1", std::string("hi!"));
}

void ns::HelloHandler::onLoad() {  
	std::cout << "onLoad HelloHandler executed" << std::endl;
	const std::string loggerComponentName = context()->getConfig()->asString(context()->getComponentXPath() + "/logger");
	logger_ = context()->findComponent<fastcgi::Logger>(loggerComponentName);
	if (!logger_) {
		std::cout << "error logger" << std::endl;
		throw std::runtime_error("cannot get component " + loggerComponentName);
	}
}

void ns::HelloHandler::onUnload() {
	std::cout << "onUnload HelloHandler executed" << std::endl;
}
