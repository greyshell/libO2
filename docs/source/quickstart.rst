Quickstart
==========

A quick guide for installing and using `libO2`_.



Installation
------------

* Clone the repository::

    $ git clone https://github.com/greyshell/libO2.git

* Install the following dependencies:

  * `gcc`_ : >= 9.2.1

  * `cmake`_ : >= 3.16.3


.. note:: `Unity`_ is not needed for using the library. You will need to
          install it **only if** you wish to run the tests.


* Create the `build` directory and navigate into it::

  .. code-block:: bash

    mkdir build

    cd build/


* Create the build environment and install the library::

    $ cmake .. && make install


* Create the build environment and install the library::

    $ cmake .. && make install


.. note:: It will copy `.so` files into `/usr/local/lib/` directory and `.h` files into `/usr/local/include/` directory.


* Reload / cache the shared libraries::

    $ ldconfig


How to use the library
-----------------------

* Write a sample program like below::

.. literalinclude:: ../../sample/demo_stack_singly_linkedlist_int.c
  :language: C


* Compile the code with `gcc`::

    $ gcc -Wall -o demo_stack_singly_linkedlist_int demo_stack_singly_linkedlist_int.c -lO2


* Run the binary`::

    $ ./demo_stack_singly_linkedlist_int


.. _gcc: https://gcc.gnu.org/

.. _cmake: https://cmake.org/

.. _Unity: http://www.throwtheswitch.org/unity

.. _libO2: https://github.com/greyshell/libO2
