import _ from "lodash";
import './style.css'
import Icon from './icon.png'
import printMe from "./print";

function component() {
    const element = document.createElement('div');
    element.innerHTML = _.join(['Hello', 'webpack']);
    // element.classList.add('hello');
    element.className = 'hello';

    // const myIcon = new Image();
    // myIcon.src = Icon;
    // element.appendChild(myIcon);

    const  myIcon = document.createElement('img');
    myIcon.src = Icon;
    element.appendChild(myIcon);

    const btn = document.createElement('button');
    btn.innerHTML = 'Click me and check the console!';
    btn.onclick = printMe;

    element.appendChild(btn);

    return element;
}

document.body.appendChild(component());