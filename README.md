gpsdsnmp
========

The aim of the gpsdsnmp project is to add SNMP support 
to [gpsd](http://www.catb.org/gpsd/). It allows 
read-only access to the data *gpsd* keeps in shared
memory.

The project consists of two main components. 

* *GPSD-MIB* defines the data that is accessible 
  through SNMP.
* *gpsdsnmp* is an AgentX based implementation 
  of *GPSD-MIB*.

GPSD-MIB
--------

The structure of GPSD-MIB follows closely the structure
*gpsd* defined for the shared memory segment. Almost all
data of the shared memory is available through SNMP. 



gpsdsnmp
--------
  
