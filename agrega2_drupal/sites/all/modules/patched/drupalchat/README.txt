DrupalChat provides one on one chat. It provides a static sleek chat bar at 
the bottom of the web browser. There is a selectable list of Online Users like
in Facebook chat. Once you choose a particular user to chat with, it creates a
new tab in the chat bar along with an attached pop-up chat window.

REQUIREMENTS
============
- This module is written for Drupal 7.x.
- Session API (optional) - if you want to use DrupalChat for anonymous users, then you need to install and enable this module.
- User Relationships (optional) - if you want to integrate DrupalChat with this module.

INSTALLATION
============

1. Download the module from drupal.org/project/drupalchat and save it to your
   modules folder.
2. Enable the DrupalChat module at admin/modules.
3. Set the Access DrupalChat permission for authenticated users at
   admin/people/permissions.

INTEGRATION WITH USER RELATIONSHIPS
===================================
1. Enable the DrupalChat UR Integration module.
2. Go to the admin/config/drupalchat/configuration and fill in the required details after
   configuring up the User Relationships module.

ADMINISTER THE DRUPALCHAT MODULE
=================================
Go to admin/config/drupalchat/configuration.


PATCHES (Missing a couple of modifications while theming. Please be careful when updating this module.)
=================================
NAME: drupalchat_add_og_rooms.patch
DESCRIPTION: Add chatrooms per OG and restrict the access to the communities to only subscribed users. Made really quickly,
 would be nice to redo with more time and contribute.

NAME: drupalchat_message_logs.patch
DESCRIPTION: Add Style for log message + avoid to add message when loading chatroom box for the first time to avoid duplication.

NAME: drupalchat_comment_users_related_text.patch
DESCRIPTION: Comment labels about number of users online. For the moment this feature is not included.

NAME: drupalchat_avoid_request_users_only_rooms.patch
DESCRIPTION: Avoid to request users per poll. Only rooms are used fror the moment.