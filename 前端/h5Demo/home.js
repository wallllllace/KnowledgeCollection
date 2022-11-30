// document.addEventListener('DOMContentLoaded', function() {
//     function createParagraph() {
//         let para = document.createElement('p');
//         para.textContent = '你点击了这个按钮！';
//         document.body.appendChild(para);
//     }

//     const buttons = document.querySelectorAll('button');
//     for(let i = 0; i < buttons.length; i++) {
//         buttons[i].addEventListener('click', createParagraph);
//     }

// });

class Person {
    name = '';

    constructor(name) {
        this.name = name;
    }

    introduceSelf(){
        alert(`HI, My name is ${this.name}`);
    }
}

const mike = new Person('Mike');
mike.introduceSelf();


class Teacher extends Person {
    work = '';
    constructor(name, work) {
        super(name);
        this.work = work;
    }
    introduceSelf(){
        alert(`HI, My name is ${this.name}, and my work is teach ${this.work}`);
    }
    grade(paper) {
        const grade = Math.floor(Math.random() * (5 - 1) + 1);
        console.log(grade);
    }
}

const teacher = new Teacher('ma', 'math');
teacher.introduceSelf();
teacher.grade(90);


var superHeroes = {
    "squadName" : "Super hero squad",
    "homeTown" : "Metro City",
    "formed" : 2016,
    "secretBase" : "Super tower",
    "active" : true,
    "members" : [
      {
        "name" : "Molecule Man",
        "age" : 29,
        "secretIdentity" : "Dan Jukes",
        "powers" : [
          "Radiation resistance",
          "Turning tiny",
          "Radiation blast"
        ]
      },
      {
        "name" : "Madame Uppercut",
        "age" : 39,
        "secretIdentity" : "Jane Wilson",
        "powers" : [
          "Million tonne punch",
          "Damage resistance",
          "Superhuman reflexes"
        ]
      },
      {
        "name" : "Eternal Flame",
        "age" : 1000000,
        "secretIdentity" : "Unknown",
        "powers" : [
          "Immortality",
          "Heat Immunity",
          "Inferno",
          "Teleportation",
          "Interdimensional travel"
        ]
      }
    ]
  };

  superHeroes.homeTown = "aa";
  superHeroes["members"][0].name
  superHeroes.members[1].name

/*
const fetchPromise = fetch('https://mdn.github.io/learning-area/javascript/apis/fetching-data/can-store/product.json');
  console.log(fetchPromise);
  fetchPromise.then(response => {
    if(!response.ok){
      throw new Error(`http error: ${response.status}`);
    }
    function headersForEach(value, key, parent){
      console.log(key + ' = ' + '"' + value + '"');
    }
    console.log(`已经收到响应${response}`);
    response.headers.forEach(headersForEach);
    return response.json();
  }).then(jsonObj => {
    console.log(jsonObj);
  }).catch(error => {
    console.error(`捕获到error：${error}`);
  });
  console.log("已发送请求……");
*/

// async function fetchProducts() {
//   try{
//     const reponse = await fetch('https://mdn.github.io/learning-area/javascript/apis/fetching-data/can-store/products.json');
//     if(!reponse.ok) {
//       throw new Error(`HTTP 请求错误：${reponse.status}`);
//     }
//     const json = await reponse.json();
//     console.log(json[0].name);
//     return json;
//   }
//   catch(error) {
//     console.error(`无法获取产品列表：${error}`);
//   }
// }
// const json = await fetchProducts(); // 这个json不是promise
// const json = fetchProducts(); // 这个json是promise
// console.log(json);


async function testFunc(){
  console.log('aaa func inner');
  return "aaa";
}

console.log('aaa func before');
// const aaa = await testFunc();
console.log('aaa func after');

async function testFunc2(){
  const aaa = await testFunc();
  return aaa;
} 

const aaa2 = testFunc2();
aaa2;

const myFun = async () => {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      // resolve(1)
      reject(2)
    },1000)
  })
  // return "aaaa";
}
myFun().then(aaa => {
  console.log(`aaa: ${aaa}`);
}).catch(bbb => {
  console.log(`bbb: ${bbb}`);
});

const myFun2 = async() => {
  try {
    const res = await myFun();
  console.log(`res: ${res}`);
  } catch (error) {
    console.log(`error: ${error}`);
  }
  
}
myFun2();

const personName = document.querySelector('#name');
const delay = document.querySelector('#delay');

function setAlarm(name, delay){
  return new Promise((resolve, reject) => {
    if(delay<0){
      throw new Error('delay 必须是正值');
    }
    window.setTimeout(() => {
      resolve(`wakeup ${name}!`);
    }, delay);
  });
}

const output = document.querySelector('#output');
const btn = document.querySelector('#set-alarm');
btn.addEventListener('click', async () => {
  // setAlarm(personName.value, delay.value)
  // .then(txt => {
  //   output.textContent = txt;
  // })
  // .catch(err => {
  //   output.textContent = err;
  // })
  try{
     const txt = await setAlarm(personName.value, delay.value);
     output.textContent = txt;
  }
  catch(err){
    output.textContent = err;
  }
});

