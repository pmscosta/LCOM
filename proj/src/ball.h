/**
 * @file ball.h
 * @author Pedro Costa, João Fidalgo
 * @date 20 Dec 2017
 * @brief File containing all the functions and informations regarding the ball during the game.
 *
 */

#ifndef __BALL_H
#define __BALL_H

#include <stdint.h>
#include "player.h"

/** @defgroup ball ball
 * @{
 *
 * Module that handles everything related to the ball during the game state.
 */

/**
 * MACROS FOR BALL
 */
#define BALLSIZE 15
#define BALL_MAX_VELOCITY 22.4
#define BALL_COEFICIENT 0.94
#define OVERLAPING_MEASURE 150
#define KICKED_IMPULSE 20
#define KICKED_MULTIPLIER 5.7
#define PUSHED_ADDER 3.7
#define MINIMUM_VELOCITY_ALLOWED 0.5
#define BALL_DRAG_COEFFIECIENT 0.93

/** @name Ball Interactions */
/**@{
 *
 * @brief Enumeration of the two possible interactions with the ball.
 *
 */

typedef enum {

	PUSHED, /**< The ball will go with the player. */
	KICKED /**< The player will kick the ball giving it some velocity */

} BALLACTIONS;

/** @} end of Ball Interactions*/

/** @name Ball Structure */
/**@{
 *
 *@brief Ball Structure containing all of its attributes
 *
 */
typedef struct {

	int x; /**< The current x-position. */
	int y;/**< The current y-position. */

	int starting_x; /**< Saving the starting x-position here. */
	int starting_y;/**< Saving the starting y-position here. */

	float vx;/**< The ball velocity in the x axis. */
	float vy;/**< The ball velocity in the y axis */

	int size;/**< The ball size, also the radius given that it is a circle, in pixels */

	uint16_t color; /**< The ball colour */

} Ball_t;

/** @} end of Ball Structure*/

/**
 * @brief The only way to get information about the ball.
 *
 * If the ball hasn't yet been defined before the first call of this function,
 * it will also create it.
 *
 * @return A pointer to the ball.
 *
 */
Ball_t * getBall();

/**
 * @brief Frees the memory occupied by the ball.
 */
void deleteBall();

/**
 * @brief Draws the ball on the Double Buffer
 *
 * @see vg_draw_circle_with_limit
 *
 */
void drawBall();

/*
 * @brief Checks if the ball is colliding with the specified player
 *
 * @param * player - pointer to the player which will be tested
 *
 * @return 1 upon collision, 0 otherwise
 */
int checkBallPlayerCollision(Player_t * player);

/*
 * @brief Updates the ball accordingly to the interaction with the player
 *
 * @param action - The action generated by the player
 * @param * player - The player that generated the action
 *
 */
void BallInteraction(BALLACTIONS action, Player_t * player);

/**
 * @brief Checks if the ball is within the field or colliding with the walls
 *
 * @return 0 if it is within, 1 if it is beyond or colliding with the x limits, 2 if it is beyond or colliding with the y limits
 *
 */
int checkBallBoundaries();

/*
 * @brief Updates the ball position and velocity in each frame
 */
void updateBall(Player_t * player_one, Player_t * player_two);

/*
 * @brief Resets the ball to the middle of the field, original position.
 *
 * Called when the game ends
 *
 */
void resetBallPosition();

/**
 * @brief Checks if someone scored a goal
 *
 * @return 0 if no goal, 1 if the goal was on the left side of the field, 2 on the right side
 */
int checkGoal();

/**
 * @brief Checks if the ball is moving
 *
 * @return 0 is it is still, 1 upon movement.
 */
int ballIsMoving();

void fixBallOverlaping(Player_t * player);

/** @} end of ball */

#endif
