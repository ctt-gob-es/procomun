Parches aplicados a este módulo

Nombre: ws_client_rest_raw_data.patch
Descripción: modifica el método de envío en los servicios REST para que permita enviar objetos JSON

Nombre: ws_client_rest_delete_null_values.patch
Descripción: elimino los valores que vengan vacíos para evitar errores por parte del orquestador

Nombre: ws_client_rest_perm_get_operations.patch
Descripción: permito el envío de parámetros por URL si la petición es por GET. Si es por POST, lo que se envía es un objeto JSON
