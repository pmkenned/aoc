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
        for (let k=j+1; k<numbers.length; k++) {
            if (numbers[i] + numbers[j] + numbers[k] == 2020) {
                console.log(numbers[i]*numbers[j]*numbers[k]);
            }
        }
    }
}
