<html>
<body>
<%@ page import="com.emergya.agrega2.arranger.util.impl.Utils"%>
<%

String version = Utils.getMessage("arranger.version");
String buildDate = Utils.getMessage("arranger.buildTime");
%> 
<h2>Semantic Agrega2 Arranger</h2>
Version: <%= version %> <br />
Build time: <%= buildDate %>
</body>
</html>
