// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from telerobot_interfaces:msg/MoveCmd.idl
// generated code does not contain a copyright notice

#ifndef TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__FUNCTIONS_H_
#define TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "telerobot_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "telerobot_interfaces/msg/detail/move_cmd__struct.h"

/// Initialize msg/MoveCmd message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * telerobot_interfaces__msg__MoveCmd
 * )) before or use
 * telerobot_interfaces__msg__MoveCmd__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_telerobot_interfaces
bool
telerobot_interfaces__msg__MoveCmd__init(telerobot_interfaces__msg__MoveCmd * msg);

/// Finalize msg/MoveCmd message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_telerobot_interfaces
void
telerobot_interfaces__msg__MoveCmd__fini(telerobot_interfaces__msg__MoveCmd * msg);

/// Create msg/MoveCmd message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * telerobot_interfaces__msg__MoveCmd__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_telerobot_interfaces
telerobot_interfaces__msg__MoveCmd *
telerobot_interfaces__msg__MoveCmd__create();

/// Destroy msg/MoveCmd message.
/**
 * It calls
 * telerobot_interfaces__msg__MoveCmd__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_telerobot_interfaces
void
telerobot_interfaces__msg__MoveCmd__destroy(telerobot_interfaces__msg__MoveCmd * msg);

/// Check for msg/MoveCmd message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_telerobot_interfaces
bool
telerobot_interfaces__msg__MoveCmd__are_equal(const telerobot_interfaces__msg__MoveCmd * lhs, const telerobot_interfaces__msg__MoveCmd * rhs);

/// Copy a msg/MoveCmd message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_telerobot_interfaces
bool
telerobot_interfaces__msg__MoveCmd__copy(
  const telerobot_interfaces__msg__MoveCmd * input,
  telerobot_interfaces__msg__MoveCmd * output);

/// Initialize array of msg/MoveCmd messages.
/**
 * It allocates the memory for the number of elements and calls
 * telerobot_interfaces__msg__MoveCmd__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_telerobot_interfaces
bool
telerobot_interfaces__msg__MoveCmd__Sequence__init(telerobot_interfaces__msg__MoveCmd__Sequence * array, size_t size);

/// Finalize array of msg/MoveCmd messages.
/**
 * It calls
 * telerobot_interfaces__msg__MoveCmd__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_telerobot_interfaces
void
telerobot_interfaces__msg__MoveCmd__Sequence__fini(telerobot_interfaces__msg__MoveCmd__Sequence * array);

/// Create array of msg/MoveCmd messages.
/**
 * It allocates the memory for the array and calls
 * telerobot_interfaces__msg__MoveCmd__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_telerobot_interfaces
telerobot_interfaces__msg__MoveCmd__Sequence *
telerobot_interfaces__msg__MoveCmd__Sequence__create(size_t size);

/// Destroy array of msg/MoveCmd messages.
/**
 * It calls
 * telerobot_interfaces__msg__MoveCmd__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_telerobot_interfaces
void
telerobot_interfaces__msg__MoveCmd__Sequence__destroy(telerobot_interfaces__msg__MoveCmd__Sequence * array);

/// Check for msg/MoveCmd message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_telerobot_interfaces
bool
telerobot_interfaces__msg__MoveCmd__Sequence__are_equal(const telerobot_interfaces__msg__MoveCmd__Sequence * lhs, const telerobot_interfaces__msg__MoveCmd__Sequence * rhs);

/// Copy an array of msg/MoveCmd messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_telerobot_interfaces
bool
telerobot_interfaces__msg__MoveCmd__Sequence__copy(
  const telerobot_interfaces__msg__MoveCmd__Sequence * input,
  telerobot_interfaces__msg__MoveCmd__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TELEROBOT_INTERFACES__MSG__DETAIL__MOVE_CMD__FUNCTIONS_H_
