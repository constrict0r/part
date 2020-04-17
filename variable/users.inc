List of users to be created. Each non-empty username listed on users will be
created.

This list can be modified by passing an *users* array when including the role
on a playbook or via *--extra-vars* from a terminal.

This variable is empty by default.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{users: [mary, jhon]}"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       users:
         - mary
         - jhon

 # To a playbook from terminal.
 ansible-playbook -i inventory my-playbook.yml -K -e \
     "{users: [mary, jhon]}"