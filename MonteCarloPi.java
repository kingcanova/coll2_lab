/*
 * Example MonteCarloPi: approximate pi using a Monte Carlo method
 *
 * Jim Teresco, The College of Saint Rose, CSC 202, Fall 2012
 *
 * $Id: MonteCarloPi.java 1960 2012-10-29 00:54:13Z terescoj $
 */

import java.util.Random;
import java.util.Scanner;

public class MonteCarloPi {

    public static void main(String[] args) {

        // create our Scanner and Random objects
        Scanner keyboard = new Scanner(System.in);
        Random random = new Random();

        // get the number of points to generate
        System.out.print("How many points to generate for this approximation of pi? ");
        int numPoints = keyboard.nextInt();

        // variable to keep track of the number of the generated points
        // that were inside the unit circle
        int inCircle = 0;

        // now loop to generate and check numPoints points
        for (int pointNum = 1; pointNum <= numPoints; pointNum++) {
            // generate our x,y coordinates
            double x = random.nextDouble();
            double y = random.nextDouble();

            // distance from the origin:
            double dist = Math.sqrt(x * x + y * y);

            // check if it's less than or equal to 1
            if (dist <= 1) {
                inCircle++;
            }
        }

        // our pi approximation
        double apxPi = (double)inCircle / numPoints * 4;

        System.out.println("Our approximation of pi: " + apxPi);

    }
}
