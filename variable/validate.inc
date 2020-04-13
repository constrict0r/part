Boolean value indicating if apply validations or not.

If set to *true* the following validations are applied:

- Verify if the user can become root.

This variable is set to *false* by default.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "validate=false"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       validate: false

 # To a playbook from terminal.
 ansible-playbook -i tests/inventory tests/test-playbook.yml -K -e \
     "validate=false"

To prevent any unexpected behaviour, it is recommended to always specify this
variable when calling this role.