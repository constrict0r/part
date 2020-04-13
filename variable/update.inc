Boolean variable that defines if update or not the apt cache.

If set to *true* the apt cache is updated.

This variable is set to *false* by default.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "update=false"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       update: false

 # To a playbook from terminal.
 ansible-playbook -i tests/inventory tests/test-playbook.yml -K -e \
     "update=false"

To prevent any unexpected behaviour, it is recommended to always specify this variable when calling this role.