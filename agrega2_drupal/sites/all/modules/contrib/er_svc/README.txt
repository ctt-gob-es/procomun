CONTENTS OF THIS FILE
---------------------

* Requirements
* Configuration

REQUIREMENTS
------------

* Drupal 7.x
* Services
* Email Registration

CONFIGURATION
-------------
No configuration is needed.  When module is active, the login process on
the user/login endpoint will use email address and password instead of username
and password

For example, on a JSON endpoint, A valid login body is POSTed as follows:

{
"mail":"myemailaddress@example.com",
"pass":"mypassword"
}
