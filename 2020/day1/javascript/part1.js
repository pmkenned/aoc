// See: https://nodejs.dev/learn/introduction-to-nodejs

fs = require('fs');

const data = fs.readFileSync("../input.txt", 'utf8');

lines = data.split("\n");

let numbers = [];
for (let i in lines) {
    const line = lines[i];
    numbers.push(parseInt(line));
}

for (let i=0; i<numbers.length; i++) {
    for (let j=i+1; j<numbers.length; j++) {
        if (numbers[i] + numbers[j] == 2020) {
            console.log(numbers[i]*numbers[j]);
        }
    }
}
