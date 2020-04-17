If an user do not specifies the *password* attribute, this password will be
setted for that user.

This password will only be setted for new users and do not affects existent
users.

This variable defaults to 1234.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{password: 4321}"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       password: 4321

 # To a playbook from terminal.
 ansible-playbook -i inventory my-playbook.yml -K -e \
     "password=4321"