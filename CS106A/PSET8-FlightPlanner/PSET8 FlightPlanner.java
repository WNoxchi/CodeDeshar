/*
 * CS106A - Programming Methodology
 * FlightPlanner.java
 * Problem Set 8: Flight Planner --- Data Structures
 * S: 21-Feb-2016 01:33
 * -----------------------------------------------------------------------------
 * Write a program that reads in a file containing flight destinations from various
 * cities, and then allow the user to plan a round-trip flight route.
 * Flight data comes from a file named flights.txt:
 *  each line consists of a pair of cities separated by an arrow ->
 * -----------------------------------------------------------------------------
 * Program should:
 * >>read in flight info from file and store in approp. data structure
 * >>display complete list of cities
 * >>allow user to select city from which to start
 * >>in a loop, print out all destinations that the user may reach directly
 *  from current city, & prompt to select next city.
 * >>once user selects round-trip route, exit from loop and print route chosen.
 */

import acm.program.*;
import acm.util.*;
import java.io.*;
import java.util.*;

public class FlightPlanner extends ConsoleProgram {

    public void run() {
        println("Welcome to Flight Planner!");

        loadFlightList();
        displayCities();
        askForRoute();
    }

    private void loadFlightList() {
        try {
            BufferedReader flightData = new BufferedReader(new FileReader("flights.txt"));
            while (true) {
                flightMap = new HashMap<String, ArrayList<String>>();
                cityList = new ArrayList<String>();

                String line = flightData.readLine();
                if (line == null) break;
                else if (line.isEmpty()) continue;
                // flightList.add(line);

                // if (!cityList.contains(line.substring(0, line.indexOf(" ->")))) {
                //     cityList.add(line.substring(0, line.indexOf(" ->")));
                // }
                processFlightData(line);
            }
            flightData.close();
        } catch (IOException wtf) {
            throw new ErrorException(wtf);
        }
    }

    private void processFlightData(String line) {
        int arrow = line.indexOf("->");
        if (arrow == -1) {
            throw new ErrorException("Illegal flight entry aww nooo Muthafucka!: " + line);
        }
        String Origin = line.substring(0, arrow).trim();
        String Destination = line.substring(arrow + 2).trim();

        loadCity(Origin);
        loadCity(Destination);
        getDestinations(Origin).add(Destination);
        // int arrow = line.indexOf("->");
        // if (arrow == -1) {
        //     throw new ErrorException("Illegal flight entry aww nooo Muthafucka!: " + line);
        // }
        // String Origin = line.substring(0, arrow).trim();
        // String Destination = line.substring(arrow + 2).trim();
        // buildRoutes(o
    }

    private void loadCity(String city) {
        if (!cityList.contains(city)) {
            cityList.add(city);
            flightMap.put(city, new ArrayList<String>());
        }
    }

    private ArrayList<String> getDestinations(String city) {
        return flightMap.get(city);
    }

    private void displayCities() {
        // println(cityList.size());                            // for debugging
        // for (int i = 0; i < flightList.size(); i++) {
        //     cityCheckList.add(flightList.get(i).substring(0, flightList.get(i).indexOf(" ->")) );
        // }
        // // println(cityCheckList);
        // for (int i = 0; i < cityCheckList.size(); i++) {
        //     if (cityList.contains(cityCheckList.get(i)) == false) {
        //         cityList.add(cityCheckList.get(i));
        //     }
        // }
        // buildFlightsMap();
        println("Here's a list of all the cities in our database:");
        for (int i = 0; i < cityList.size(); i++) {
            println("  - " + cityList.get(i));
        }
    }

    private void askForRoute() {
        println("Let's plan a round-trip route.");
        Origin = readLine("Enter a starting city: ");
        ArrayList<String> route = new ArrayList<String>();
        route.add(Origin);
        String currentCity = Origin;

        // while (true) {
        //     if (!String.class.isInstance(originCity) || inDB(originCity) != true ) {
        //         println("That city is not in our database.");
        //         originCity = readLine("Enter a starting city: ");
        //     } else {
        //         break;
        //     }
        // }
        while (true) {
            String nextCity = getNextCity(Origin);
            route.add(nextCity);
            if (nextCity.equals(Origin)) break;
            currentCity = nextCity;
        }
        displayRoute(route);
    }

    private void displayRoute(ArrayList<String> route) {
        println("The route you've chosen is: ");
        for (int i = 0; i < route.size(); i++) {
            if (i > 0) print(" -> ");
            print(route.get(i));
        }
        println();
    }

    private String getNextCity(String city) {
        String nextCity = null;
        ArrayList<String> DestinationList = getDestinations(city);
        while (true) {
            println("From " + Origin + " you can fly to: ");
            displayDestinations(DestinationList);
            String prompt = "Where do you want to go from " + city + "? ";
            nextCity = readLine(prompt);
            if (DestinationList.contains(nextCity)) break;
            println("You can't get to that city by a direct flight.");
        }
        return nextCity;
        // cityCheckList.clear();
        // println(cityCheckList);      // functionality-check stub
        // routeList.clear();
        // askForRoute();

        // // Builds an ArrayList of only the routes from that one city
        // for (int i = 0; i < flightList.size(); i++) {
        //     if (flightList.get(i).substring(0, flightList.get(i).indexOf(" ->")).equals(city)) {
        //         routeList.add(flightList.get(i));
        //     }
        // }
        // // Adds the ArrayList of routes to a HashMap with the originCity as Key
    }

    private void displayDestinations(ArrayList<String> cityList) {
        for (int i = 0; i < cityList.size(); i++) {
            String city = cityList.get(i);
            println(" - " + city);
        }
    // checks if a city is in the database
    // private boolean inDB(String city) {
    //     if (cityList.contains(city)) return true;
    //     return false;
    }

    private String Origin;
    private String Destination;
    // private String originCity;
    // // private boolean cityCheck;
    // private ArrayList <String> tempArray = new ArrayList <String> ();
    // private ArrayList <String> routeList = new ArrayList <String> ();
    private ArrayList <String> cityList = new ArrayList <String> ();
    // private ArrayList <String> cityCheckList = new ArrayList <String> ();
    private ArrayList <String> flightList = new ArrayList <String> ();

    private HashMap <String, ArrayList<String>> flightMap = new HashMap <String, ArrayList<String>> ();
    // private ArrayList <String> cityList = new ArrayList <String> ();

}

/* Trash code:

// cityCheck = true;

// for (int j = 0; j < cityCheckList.size(); j++) {
//     if (cityList.get(i) == cityCheckList.get(i)) {
//         cityCheck = false;
//     }
// }
// if (cityCheck == true) {
//     // cityCheckList.add(cityList.get(i));
//     println(cityList.get(i));
// }


// println(cityList);
// println(cityCheck);


// Display cityList contents [stub]
// for (int i = 0; i < flightList.size(); i++) {
//     println(flightList.get(i).toString());
// }

 */
