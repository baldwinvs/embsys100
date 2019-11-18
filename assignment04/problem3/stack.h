#ifndef STACK_H
#define STACK_H

#include <stdint.h>

/** Initialize the stack internals.
 */
void stackInit(void);

/** Push a value to the stack.
 *
 * \returns 0 if the stack is full, 1 if the push was successful.
 */
int32_t stackPush(const int32_t value //!< The value to push onto the stack.
                  );

/** Pop the top element of the stack.
 *
 * \returns 0 if the stack is empty, 1 if the pop was successful.
 */
int32_t stackPop(int32_t* value //!< The value that will store the top element before popping.
                 );

/** Check if the stack is empty.
 *
 * \returns 0 if the stack is not empty, 1 if the stack is empty.
 */
int32_t isStackEmpty(void);

/** Check if the stack is full.
 *
 * \returns 0 if the stack is not full, 1 if the stack is full.
 */
int32_t isStackFull(void);

#endif // STACK_H