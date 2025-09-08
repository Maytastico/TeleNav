// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from telerobot_interfaces:msg/MoveCmd.idl
// generated code does not contain a copyright notice
#include "telerobot_interfaces/msg/detail/move_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
telerobot_interfaces__msg__MoveCmd__init(telerobot_interfaces__msg__MoveCmd * msg)
{
  if (!msg) {
    return false;
  }
  // joy_x
  // joy_y
  // cmd
  return true;
}

void
telerobot_interfaces__msg__MoveCmd__fini(telerobot_interfaces__msg__MoveCmd * msg)
{
  if (!msg) {
    return;
  }
  // joy_x
  // joy_y
  // cmd
}

bool
telerobot_interfaces__msg__MoveCmd__are_equal(const telerobot_interfaces__msg__MoveCmd * lhs, const telerobot_interfaces__msg__MoveCmd * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // joy_x
  if (lhs->joy_x != rhs->joy_x) {
    return false;
  }
  // joy_y
  if (lhs->joy_y != rhs->joy_y) {
    return false;
  }
  // cmd
  if (lhs->cmd != rhs->cmd) {
    return false;
  }
  return true;
}

bool
telerobot_interfaces__msg__MoveCmd__copy(
  const telerobot_interfaces__msg__MoveCmd * input,
  telerobot_interfaces__msg__MoveCmd * output)
{
  if (!input || !output) {
    return false;
  }
  // joy_x
  output->joy_x = input->joy_x;
  // joy_y
  output->joy_y = input->joy_y;
  // cmd
  output->cmd = input->cmd;
  return true;
}

telerobot_interfaces__msg__MoveCmd *
telerobot_interfaces__msg__MoveCmd__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  telerobot_interfaces__msg__MoveCmd * msg = (telerobot_interfaces__msg__MoveCmd *)allocator.allocate(sizeof(telerobot_interfaces__msg__MoveCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(telerobot_interfaces__msg__MoveCmd));
  bool success = telerobot_interfaces__msg__MoveCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
telerobot_interfaces__msg__MoveCmd__destroy(telerobot_interfaces__msg__MoveCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    telerobot_interfaces__msg__MoveCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
telerobot_interfaces__msg__MoveCmd__Sequence__init(telerobot_interfaces__msg__MoveCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  telerobot_interfaces__msg__MoveCmd * data = NULL;

  if (size) {
    data = (telerobot_interfaces__msg__MoveCmd *)allocator.zero_allocate(size, sizeof(telerobot_interfaces__msg__MoveCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = telerobot_interfaces__msg__MoveCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        telerobot_interfaces__msg__MoveCmd__fini(&data[i - 1]);
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
telerobot_interfaces__msg__MoveCmd__Sequence__fini(telerobot_interfaces__msg__MoveCmd__Sequence * array)
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
      telerobot_interfaces__msg__MoveCmd__fini(&array->data[i]);
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

telerobot_interfaces__msg__MoveCmd__Sequence *
telerobot_interfaces__msg__MoveCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  telerobot_interfaces__msg__MoveCmd__Sequence * array = (telerobot_interfaces__msg__MoveCmd__Sequence *)allocator.allocate(sizeof(telerobot_interfaces__msg__MoveCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = telerobot_interfaces__msg__MoveCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
telerobot_interfaces__msg__MoveCmd__Sequence__destroy(telerobot_interfaces__msg__MoveCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    telerobot_interfaces__msg__MoveCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
telerobot_interfaces__msg__MoveCmd__Sequence__are_equal(const telerobot_interfaces__msg__MoveCmd__Sequence * lhs, const telerobot_interfaces__msg__MoveCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!telerobot_interfaces__msg__MoveCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
telerobot_interfaces__msg__MoveCmd__Sequence__copy(
  const telerobot_interfaces__msg__MoveCmd__Sequence * input,
  telerobot_interfaces__msg__MoveCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(telerobot_interfaces__msg__MoveCmd);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    telerobot_interfaces__msg__MoveCmd * data =
      (telerobot_interfaces__msg__MoveCmd *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!telerobot_interfaces__msg__MoveCmd__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          telerobot_interfaces__msg__MoveCmd__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!telerobot_interfaces__msg__MoveCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
