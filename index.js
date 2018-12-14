const express = require('express');
const SerialPort = require('serialport');
// const Readline = //require('@serialport/parser-readline');
const app = express();
const port = 8000;
const myport = new SerialPort('/dev/tty.usbmodem1421', { baudRate: 9600 });
const parser = myport.pipe(new SerialPort.parsers.Readline({ delimiter: '\n' }));

// Read the port data
myport.on("open", () => {
  console.log('serial port open');
});
parser.on('data', data =>{
  console.log('arduino says:', data);
});
app.use(express.static('public'));
app.get('/', (request, response) => {
  response.send('Hello from Express!'+request.query.message)
  myport.write(request.query.message, (err) => {
    if (err) {
      return console.log('Error on write: ', err.message);
    }
    console.log('message written');
  });
})

app.listen(port, (err) => {
  if (err) {
    return console.log('something bad happened', err)
  }

  console.log(`server is listening on ${port}`)
})
