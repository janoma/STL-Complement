Iterator
========

.. cpp:namespace:: stdc

.. cpp:class:: template <typename Container> \
               back_emplacer_operator

   Function object that calls ``emplace_back()`` on the container for which it
   was constructed, ``std::forward``'ing the arguments to the container.

   .. cpp:function:: explicit back_emplacer_operator(Container& container)

      :param container: Reference to the container that supports ``emplace_back``
      :type container: ``Container&``

   .. cpp:function:: template <typename... Args> \
                     back_emplacer_operator<Container>& operator()(Args&&...)

      Calls ``std::forward`` on the given arguments to pass them to the
      container's ``emplace_back`` method.

      :return: ``*this``

   .. cpp:member:: private Container* container
