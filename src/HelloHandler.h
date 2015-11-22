#include "settings.h"

#include <iostream>
#include <stdexcept>

#include "fastcgi2/logger.h"
#include "fastcgi2/config.h"
#include "fastcgi2/stream.h"
#include "fastcgi2/handler.h"
#include "fastcgi2/request.h"
#include "fastcgi2/component.h"
#include "fastcgi2/component_factory.h"

#ifdef HAVE_DMALLOC_H
#include <dmalloc.h>
#endif

namespace ns {
	class HelloHandler : virtual public fastcgi::Component, virtual public fastcgi::Handler {
	public:
		HelloHandler(fastcgi::ComponentContext *context);
		virtual ~HelloHandler();

		virtual void onLoad();
		virtual void onUnload();

		virtual void handleRequest(fastcgi::Request *req, fastcgi::HandlerContext *handlerContext);

	private:
		fastcgi::Logger *logger_;
	};

	
	FCGIDAEMON_REGISTER_FACTORIES_BEGIN()
	FCGIDAEMON_ADD_DEFAULT_FACTORY("hello", HelloHandler)
	FCGIDAEMON_REGISTER_FACTORIES_END()
}