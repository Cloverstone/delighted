<?php
// include 'PhpSerial.php';

// // Let's start the class
// $serial = new PhpSerial;

// // First we must specify the device. This works on both linux and windows (if
// // your linux serial device is /dev/ttyS0 for COM1, etc)
// $serial->deviceSet("/dev/cu.usbmodem1411");

// // We can change the baud rate, parity, length, stop bits, flow control
// $serial->confBaudRate(9600);
// // $serial->confParity("none");
// // $serial->confCharacterLength(8);
// // $serial->confStopBits(1);
// // $serial->confFlowControl("none");

// // Then we need to open it
// $serial->deviceOpen();

// // To write into
// $serial->sendMessage("+6=");
// // Then we need to open it
// $serial->deviceClose();


$f = fopen("/dev/cu.usbmodem1421", "w");
sleep(2);
fwrite($f, '+6=');
fclose($f);

// $element = exec("cu -l /dev/cu.usbmodem1421;", $output);

// 
// exec("stty -f /dev/tty.usbmodem621 cs8 9600 -hup ignbrk -brkint -icrnl -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts");