/*
 * ----------------------------------------------------------------------------
 *          Header file for FND/LED interface functions
 * ----------------------------------------------------------------------------
 */

#ifndef FND_H
#define FND_H

// function prototypes
void fnd_init(void);
void fnd_write(uint8_t, uint8_t);
void fnd_clear(uint8_t);
void fnd_clear_all(void);
void fnd_write_number(uint8_t, uint8_t, uint8_t);
void fnd_write_numbers(uint16_t num);
void led_write(uint8_t);
#endif
