List of repositories to add to the apt sources.

This list can be modified by passing a *repositories* array when including the
role on a playbook or via *--extra-vars* from a terminal.

This variable is empty by default.

.. substitution-code-block:: bash

 # Including from terminal.
 ansible localhost -m include_role -a name=|AUTHOR|.|PROJECT| -K -e \
     "{repositories: [{ \
          name: multimedia, \
          repo: 'deb http://www.debian-multimedia.org sid main' \
      }]}}"

 # Including on a playbook.
 - hosts: servers
   roles:
     - role: |AUTHOR|.|PROJECT|
       repositories:
         - name: multimedia
           repo: deb http://www.debian-multimedia.org sid main

 # To a playbook from terminal.
 ansible-playbook -i inventory my-playbook.yml -K -e \
     "{repositories: [{ \
          name: multimedia, \
          repo: 'deb http://www.debian-multimedia.org sid main' \
      }]}}"