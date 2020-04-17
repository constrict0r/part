Absolute file path or URL to a *.yml* file containing ansible tasks to
execute.

Each file or URL on this variable will be checked to see if it exists and if
it does, the task is executed.

This variable is empty by default.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{user_tasks: [item_path: https://is.gd/vVCfKI, item_expand: false]}"

 # Or:
 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{user_tasks: [https://is.gd/vVCfKI], expand: false}"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       user_tasks:
         - item_path: https://is.gd/vVCfKI
           item_expand: false

 # Or:
 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       user_tasks:
         - https://is.gd/vVCfKI
       expand: false

 # To a playbook from terminal.
 ansible-playbook -i inventory my-playbook.yml -K -e \
     "{user_tasks: [item_path: https://is.gd/vVCfKI, item_expand: false]}"

 # Or:
 # To a playbook from terminal.
 ansible-playbook -i inventory my-playbook.yml -K -e \
     "{user_tasks: [https://is.gd/vVCfKI], expand: false}"