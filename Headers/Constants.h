#pragma once

// Max number of PCs in the lab
const int MAX_CPUS = 5;
// The number we use to indicate that something doesn't exist
const int DOES_NOT_EXIST = -1;
// Base id used in PCs of the lab
const int BASE_ID = 1000;
// Possible options in our app; no more, no less
enum OPTIONS {
  SHOW_INFO = 1,
  TURN_ON,
  TURN_OFF,
  CONNECT_NET,
  DISCONNECT_NET,
  DOWNLOAD_FILE,
  COPY_FILE,
  EXIT
};