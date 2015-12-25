# fastcgilab

### Create Note
***

**Request:** 
* url: `/notes/(user_id)`
* method: `post`
* body: `{name: "string", header: "string", body: "string"}`

**Response:**
* content/type: `application/json`
* code:
    * _Success_ - `201 HTTP_CREATED`
    * _Error_ - `404`
    * _Bad Request_ - `400`
* header:
    * _Locatin_ - `/notes/(user_id)/(note_id)`
* body: `{id: "note_id"}`

### Edit Note
***

**Request:** 
* url: `/notes/(user_id)/(note_id)`
* method: `put`
* body: `{fields: {name: "string", header: "string", body: "string"}}`

**Response:**
* content/type: `application/json`
* code:
    * _Success_- `200`
    * _Error_- `404`   
    * _Bad Request_ - `400`
* body: `empty`

### Delete Note
***

**Request:** 
* url: `/notes/(user_id)/(note_id)`
* method: `delete`

**Response:**
* content/type: `application/json`
* code:
    * _Success_- `200`
    * _Not found_- `404`
* body: `empty`

### List Notes
***

**Request:** 
* url: `/notes/(user_id)`
* method: `get`
* params: `sort_field=field_name, order=acs|dcs, from=unsign_int, to=unsign_int`

**Response:**
* content/type: `application/json`
* code:
    * _Success_- `200`
    * _Not found_- `404`
* body: `{notes: ['/notes/(user_id)/(note_id_1)', '/notes/(user_id)/(note_id_2)', '/notes/(user_id)/(note_id_2)']}`
    
