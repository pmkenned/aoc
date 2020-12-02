// See: https://nodejs.dev/learn/introduction-to-nodejs

fs = require('fs');

const data = fs.readFileSync("../input.txt", 'utf8');

console.log(data);
