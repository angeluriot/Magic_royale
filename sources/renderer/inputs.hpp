#ifndef INPUTS_HPP
#define INPUTS_HPP

/**
 * @brief An enum to manage the inputs.
 */
enum class Key
{
	Up,		// Up arrow
	Left,	// Left arrow
	Right,	// Right arrow
	Down,	// Down arrow
	Enter	// Enter key
};

/**
 * @brief Wait until the user press a key.
 *
 * @return the pressed key
 */
Key wait_for_key();

#endif
