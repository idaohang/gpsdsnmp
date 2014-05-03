/*
 *
 *
 * Shamelessly adapted from 
 * http://openhpi.sourceforge.net/subagent-manual/c167.html
 *
 * See also: http://www.net-snmp.org/docs/man/snmp_agent_api.html
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include <gps.h>
#include "gpsdFix/gpsdFix.h"
        
static int keep_running;

/* gps_data_t as global variable */
gps_data_t *gpsdsnmp_data = NULL;


RETSIGTYPE stop_server(int a) {
    keep_running = 0;
}


int main (int argc, char **argv) {

  int fp;
  char buffer[512];
  char *xixEventId, *xixEventText;
  struct stat st;

  /* Change below if you want to be a SNMP master agent */
  int agentx_subagent = 1;


  /* Print log errors to stderr */
  snmp_enable_stderrlog();


  /* Enable below for debugging */
  //snmp_set_do_debugging(1);
 

  /* Are we an AgentX subagent? */
  if (agentx_subagent) {

    /* Make us an AgentX client. */
    netsnmp_ds_set_boolean(NETSNMP_DS_APPLICATION_ID, 
                NETSNMP_DS_AGENT_ROLE, 1);
  }


  /* Initialize the agent library */
  init_agent("gpsdsnmp");


  /* Initialise MIB code */
  init_gpsdFix();


  /* Read config file: NAME.conf */
  init_snmp("gpsdsnmp");


  /* Initialised port 161/UDP if we're going to be 
   * an SNMP master agent */
  if (!agentx_subagent)
    init_master_agent();  


  /* In case we receive a request to stop (kill -TERM or kill -INT) */
  keep_running = 1;
  signal(SIGTERM, stop_server);
  signal(SIGINT, stop_server);


  /* Main loop */
  while(keep_running) {

      /* Try to open shared memory segment of gpsd */
      while(keep_running) {
          
      }

  }


  /* Shutdown */
  snmp_shutdown("gpsdsnmp");
  return 1;
}
