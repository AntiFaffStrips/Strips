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


## To Do:

### Euroscope side
- [ ] Create blank DLL project and add ES interface (using plug in development guide - DON'T FORGET PLIGIN TYPO!)
- [ ] Identify controller ICAO and position
- [ ] On load (or command), identify all relevant flight plans and their current states
- [ ] Continuously identify all new relevant flight plans
- [ ] Extract relevant data for each flight plan and store locally
- [ ] Implement methods to edit the datablock values (as if controller were doing it)

### Middle
- [ ] Decide how best to create middle
- [ ] Work out how to emulate vStrips
- [ ] Format and print paper flight strips

### UI side
- [ ] Create basic UI (decide how to do)
- [ ] Add paper mode functionality
- [ ] Add electronic mode functionality

## Contributing
As you will already know this is a private repository but if you are new and would like to contribute then please read the [contributing guide](https://github.com/JonathanFerguson1/Strips/blob/master/.github/Contribution%20Guide.md) first
