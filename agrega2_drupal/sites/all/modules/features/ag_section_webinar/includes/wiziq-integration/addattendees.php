<?php

require 'vendor/autoload.php';

use mikemix\Wiziq;

$auth    = new Wiziq\API\Auth('gG7u8svT8QM7xF2wxGIK3Q==', '8X5KRQTQtiE=');
$gateway = new Wiziq\API\Gateway($auth);
$api     = new Wiziq\API\ClassroomApi($gateway);

try {
  $classroomId = 5959140;
  $attendees   = Wiziq\Entity\Attendees::build()
    ->add(19079, 'Almundena', 'es-ES')
    ->add(25642, 'MJ Cordero', 'es-ES');
  // add more if needed

  $response = $api->addAttendeesToClass($classroomId, $attendees);

  printf('Attendees to class %d added: %s', $classroomId, var_export($response, true));
} catch (Wiziq\Common\Api\Exception\CallException $e) {
  die($e->getMessage());
} catch (Wiziq\Common\Http\Exception\InvalidResponseException $e) {
  die($e->getMessage());
}