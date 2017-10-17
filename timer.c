/*
   Timer helper routine -- compare values returned by gettimeofday
   system call and return a number of seconds.
   Taken from Parallel Mesh Database
   Jim Teresco, CS 338, Williams College
   Mon Feb 10 10:55:31 EST 2003
   CS 341, Mount Holyoke College
   CS 400, Siena College
*/
#include <stdlib.h>
#include <sys/time.h>

/*
 * wall clock time:
 * call to get the difference in time to the call
 *
 * gettimeofday(&tp, NULL);
 *
 */

double diffgettime(struct timeval tp1, struct timeval tp2) {
   int delta[2] ;

   delta[0] = tp2.tv_sec  - tp1.tv_sec ;
   delta[1] = tp2.tv_usec - tp1.tv_usec ;

   /*  See if we've wrapped and deal with it accordingly: */
   if( delta[1] < 0 ) {
       delta[0] = delta[0] - 1  ;
       delta[1] = delta[1] + 1000000 ;
    }

   return( (double) delta[0] + (double) delta[1]*1.0E-6 ) ;
}
