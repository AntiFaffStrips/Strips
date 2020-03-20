# Strips
VATSIM Flight Progress Strip Simulation

## Aims
* Enable simulation of Aerodrome based Air Traffic Controlling using Flight Progress Strips (Strips)

## Objectives
### Conditions
* Must work with Euroscope
* Must not interfere with other controllers' data
* Must not violate VATSIM CoC

### Solution Concepts
* Simulation of both electronic and paper strips
* Interface with electronic strips via PC
* Electronic strips retain and share data with other controllers (like vStrips does)
* Paper strips can be generated and printed - after that, manipulation and storage happens locally to controller, so can be ignored by solution
* Potential for different (automatically detected) strip board layouts based on controller position
* Potential for remote PC to control paper strips (could this be expanded to tablets?)

### Success Criteria
The solution will:
* Detect which airport controller is at
* Generate strips for all relevant aircraft
  * Strips should contain all pertinent detail (see CAP493: MATS Pt. 1, Appendix D, Section 3.)
* Allow controller to choose paper or electronic mode:
  * In electronic mode, strips can be manipulated. Data will be transferred back to Euroscope, as if the controller was controlling normally. Functionality essentially copying vStrips
  * In paper mode, strips are printed once generated
