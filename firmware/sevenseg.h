/*
 * File:   sevenseg.h
 * Author: aaronmorrison
 *
 * Created on March 16, 2018, 5:16 PM
 */

#ifndef SEVENSEG_H
#define	SEVENSEG_H

#ifdef	__cplusplus
extern "C" {
#endif

/* map of what all pins are to what all sevensegment pins
 * SEGA -> RA0
 * SEGB -> RA2
 * SEGC -> RB1
 * SEGD -> RA4
 * SEGE -> RA3
 * SEGF -> RA1
 * SEGG -> RB0
 * SEGDP-> RA5
 *
 *
 * HIGH bits of decoder pick display
 * DIS0 -> RC3  * RC5 (least significant)
 * DIS1 -> RC3' * RC5'
 * DIS2 -> RC3  * RC5'
 * DIS3 -> RC3' * RC5 (most significant)
 *
 * If DIS0:
 * DIG0 -> RC4  * RC2
 * DIG2 -> RC4  * RC2'
 * DIG1 -> RC4' * RC2
 * DIG3 -> RC4' * RC2'
 *
 * If DIS1
 * DIG0 -> RC4  * RC2
 * DIG1 -> RC4  * RC2'
 * DIG2 -> RC4' * RC2
 * DIG3 -> RC4' * RC2'
 *
 * If DIS1
 * DIG0 -> RC4  * RC2
 * DIG1 -> RC4  * RC2'
 * DIG2 -> RC4' * RC2
 * DIG3 -> RC4' * RC2'
 *
 * If DIS1
 * DIG0 -> RC4  * RC2
 * DIG1 -> RC4  * RC2'
 * DIG2 -> RC4' * RC2
 * DIG3 -> RC4' * RC2'
 */

void sevseg_init();
void sevseg_put_number(int digit, int display, int value);

#ifdef	__cplusplus
}
#endif

#endif	/* SEVENSEG_H */

