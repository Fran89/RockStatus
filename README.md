#RockStatus

A Monitoring Program for the Kinemetrics Rock Family of Instruments

This RockStatus program is a program that reads from the metadata streams provided by rock2ew modules. It has been written in QT and C++ in order to have full compatibility for other platforms. 

============
####Features:
* Shows updated status for every station (it automatically configures stations)
* Shows you a lot of statistics from stations provided directly from the station.
* Potential for a lot of features to be added (see below)

=============
#### Color Coding

* Coming Soon!

=============
####Instructions:
In EW:

1. Setup a ringtocoax to transmit the tracebuf2 packets to the computer which will run K2Status.

In K2Status:

1. In the Connections Menu:
2. Put the IP of the interface you are to recieve the UDP packets containing the K2 Info (or 0.0.0.0 which is self at all interfaces). 
3. That's it.

=============
####To Do:
1. Color Code the values
2. Add detector for different rock istruments (Granite, Etna2, etc).
3. Work on bugs, currently none found.
4. Add logging.
5. Add persistence.
6. ~~Test using multiple stations.~~
7. Add the ability to graph data.
8. Control graph time span (currently all is presented).

=============
####Log File:

* Coming Soon!

=============
If anyone is interested in this proyect or would like to help, contact me!

######Credits:
* The Puerto Rico Strong Motion Program for their help and support.
* The people over at Instrumental Software Technologies, Inc. (ISTI) @ http://www.isti.com/
* Everyone who has ever worked with in the development of earthworm @ http://earthwormcentral.org
* The QT Community @ http://qt-project.org/

Thanks,
Fran89.
