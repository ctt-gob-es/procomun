Agrega2 XML 2 RDF Utility

Steps to EXECUTE:

* Compile classes and generate a JAR: XML2RDF.jar (there is a default one generated in 'jar' folder).
* Create a config.xml like the one in 'jar' folder. Change the parameters as you wish, and locate it in the same directory of the Jar file generated.
* Execute from the directory as: java -jar XML2RDF.jar

Config.xml

<LOM2RDF>
	<SOURCE_URL>http://www.agrega.es/ont/lom2owl#</SOURCE_URL>
	<SOURCE_FILE>ONTOLOGY_FILE_PATH</SOURCE_FILE>
	<XML_Folder>XMLs_SOURCE_FOLDER</XML_Folder>
	<OUTPUT_Format>N-TRIPLE</OUTPUT_Format>
	<OUTPUT_Folder>OUTPUT_FOLDER_PATH</OUTPUT_Folder>
	<LOM_PREFIX>lomes</LOM_PREFIX>
	<PORT>XXX</PORT> <!-- UNUSED -->
	<DATASET_NAME>agrega_dataset</DATASET_NAME>
	<RECORDS>ALL</RECORDS> <!-- It could be a number of records -->
	<DumpFileName>OUTPUT_FILE_NAME</DumpFileName>
</LOM2RDF>

If the OUTPUT_FOLDER_PATH/OUTPUT_FILE_NAME.nt file already exists, the program will generate a OUTPUT_FOLDER_PATH/OUTPUT_FILE_NAME_<COUNTER>.nt file, where counter will be the first number which associated file name doesn't exist.
