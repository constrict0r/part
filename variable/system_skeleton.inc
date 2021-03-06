URL or list of URLs pointing to git skeleton repositories containing layouts
of directories and configuration files.

Each URL on system_skeleton will be checked to see if it points to a valid git
repository, and if it does, the git repository is cloned.

The contents of each cloned repository will then be copied to the root of the
filesystem as a simple method to apply system-wide configuration.

This variable is empty by default.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{system_skeleton: [item_path: https://gitlab.com/huertico/server, item_expand: false]}"

 # Or:
 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{system_skeleton:https://gitlab.com/huertico/server, expand: false}"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       system_skeleton:
         - item_path: https://gitlab.com/huertico/server
           item_expand: false
         - item_path: https://gitlab.com/huertico/client
           item_expand: false

 # Or:
 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       system_skeleton:
         - https://gitlab.com/huertico/server
         - https://gitlab.com/huertico/client
       expand: false

 # To a playbook from terminal.
 ansible-playbook -i inventory my-playbook.yml -K -e \
     "{system_skeleton: [item_path: https://gitlab.com/huertico/server, item_expand: false]}"

 # Or:
 # To a playbook from terminal.
 ansible-playbook -i inventory my-playbook.yml -K -e \
     "{system_skeleton: [https://gitlab.com/huertico/server], expand: false}"