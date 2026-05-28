Instructions
============

The `Makefile` that generates TrueType font files, depends on the RetroFont_
package. Please follow the installation instructions_ carefully, as this
package needs dependencies that are tricky to install.

The following command generates the TrueType font files.

.. code:: Makefile

    make

This process may take a while, if you have multiple CPU cores available, you
can use the `-j` option to speed things up. E.g., if you have 14 CPU cores,
you can run the following command:

.. code:: Makefile

    make -j 14

Additionally, the fonts can be installed using:

.. code:: Makefile

    make install


.. _Retrofont: https://retrofont.readthedocs.io
.. _instructions: https://retrofont.readthedocs.io/en/latest/install.html
