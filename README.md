# High-Energy-muon-Binary-Classifier-
Machine learning neural binary classifier for muon interactions, build on SuperKamiokande 

Hello, World! 

So this is the folder with basically everything you might need to replicate the results I presented as 3rd year Project Report.

The sim folder contains all the files I used to build the simulation on Geant4, for the installation of the toolkit (Geant4 is a toolkit for particle-matter interactions) I followed a tutorial on you tube, precisly PhysicsMAtter playlist about geant4. Oh, the installation has been done on a virtual machine running with Ubuntu, cause it's easier. Once the installation is done to have a nice out file, I suggest to use the prompt command:

./sim runs.mac | tee 'File_name' 

which will run the simulation with the command given in the runs.mac file and print the output on the file given. 
Be careful, runs.mac has been set to run 1000 events, to test it I'd suggest to reduce it to 1 (open the file and change it to '\run\beamOn 1'

The other files are Jupyter Notebooks, hence based on Python that take the out file from the simulation and get info.
There's also a plotting function to get distrubutions.

Have fun.

