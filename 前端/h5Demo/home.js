document.addEventListener('DOMContentLoaded', function() {
    function createParagraph() {
        let para = document.createElement('p');
        para.textContent = '你点击了这个按钮！';
        document.body.appendChild(para);
    }

    const buttons = document.querySelectorAll('button');
    for(let i = 0; i < buttons.length; i++) {
        buttons[i].addEventListener('click', createParagraph);
    }

});

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