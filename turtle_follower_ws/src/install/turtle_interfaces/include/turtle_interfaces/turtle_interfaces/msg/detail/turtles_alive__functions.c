// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtle_interfaces:msg/TurtlesAlive.idl
// generated code does not contain a copyright notice
#include "turtle_interfaces/msg/detail/turtles_alive__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `turtles`
#include "turtle_interfaces/msg/detail/turtle_position__functions.h"

bool
turtle_interfaces__msg__TurtlesAlive__init(turtle_interfaces__msg__TurtlesAlive * msg)
{
  if (!msg) {
    return false;
  }
  // turtles
  if (!turtle_interfaces__msg__TurtlePosition__Sequence__init(&msg->turtles, 0)) {
    turtle_interfaces__msg__TurtlesAlive__fini(msg);
    return false;
  }
  return true;
}

void
turtle_interfaces__msg__TurtlesAlive__fini(turtle_interfaces__msg__TurtlesAlive * msg)
{
  if (!msg) {
    return;
  }
  // turtles
  turtle_interfaces__msg__TurtlePosition__Sequence__fini(&msg->turtles);
}

bool
turtle_interfaces__msg__TurtlesAlive__are_equal(const turtle_interfaces__msg__TurtlesAlive * lhs, const turtle_interfaces__msg__TurtlesAlive * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // turtles
  if (!turtle_interfaces__msg__TurtlePosition__Sequence__are_equal(
      &(lhs->turtles), &(rhs->turtles)))
  {
    return false;
  }
  return true;
}

bool
turtle_interfaces__msg__TurtlesAlive__copy(
  const turtle_interfaces__msg__TurtlesAlive * input,
  turtle_interfaces__msg__TurtlesAlive * output)
{
  if (!input || !output) {
    return false;
  }
  // turtles
  if (!turtle_interfaces__msg__TurtlePosition__Sequence__copy(
      &(input->turtles), &(output->turtles)))
  {
    return false;
  }
  return true;
}

turtle_interfaces__msg__TurtlesAlive *
turtle_interfaces__msg__TurtlesAlive__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_interfaces__msg__TurtlesAlive * msg = (turtle_interfaces__msg__TurtlesAlive *)allocator.allocate(sizeof(turtle_interfaces__msg__TurtlesAlive), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_interfaces__msg__TurtlesAlive));
  bool success = turtle_interfaces__msg__TurtlesAlive__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_interfaces__msg__TurtlesAlive__destroy(turtle_interfaces__msg__TurtlesAlive * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_interfaces__msg__TurtlesAlive__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_interfaces__msg__TurtlesAlive__Sequence__init(turtle_interfaces__msg__TurtlesAlive__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_interfaces__msg__TurtlesAlive * data = NULL;

  if (size) {
    data = (turtle_interfaces__msg__TurtlesAlive *)allocator.zero_allocate(size, sizeof(turtle_interfaces__msg__TurtlesAlive), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_interfaces__msg__TurtlesAlive__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_interfaces__msg__TurtlesAlive__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtle_interfaces__msg__TurtlesAlive__Sequence__fini(turtle_interfaces__msg__TurtlesAlive__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtle_interfaces__msg__TurtlesAlive__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtle_interfaces__msg__TurtlesAlive__Sequence *
turtle_interfaces__msg__TurtlesAlive__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_interfaces__msg__TurtlesAlive__Sequence * array = (turtle_interfaces__msg__TurtlesAlive__Sequence *)allocator.allocate(sizeof(turtle_interfaces__msg__TurtlesAlive__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_interfaces__msg__TurtlesAlive__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_interfaces__msg__TurtlesAlive__Sequence__destroy(turtle_interfaces__msg__TurtlesAlive__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_interfaces__msg__TurtlesAlive__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_interfaces__msg__TurtlesAlive__Sequence__are_equal(const turtle_interfaces__msg__TurtlesAlive__Sequence * lhs, const turtle_interfaces__msg__TurtlesAlive__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_interfaces__msg__TurtlesAlive__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_interfaces__msg__TurtlesAlive__Sequence__copy(
  const turtle_interfaces__msg__TurtlesAlive__Sequence * input,
  turtle_interfaces__msg__TurtlesAlive__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_interfaces__msg__TurtlesAlive);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_interfaces__msg__TurtlesAlive * data =
      (turtle_interfaces__msg__TurtlesAlive *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_interfaces__msg__TurtlesAlive__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_interfaces__msg__TurtlesAlive__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_interfaces__msg__TurtlesAlive__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
