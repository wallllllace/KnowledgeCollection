import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';


function UserInfo(props){
  function Avatar(avatarProps){
    return (
      <img className='Avatar'
        src={avatarProps.avatarUr}
        alt={avatarProps.name}
      />
    );
  }
  function UserInfoName(userInfoNameProps){
    return (
      <div className='UserInfo-name'>
        {userInfoNameProps.name}
      </div>
    );
  }
  return (
    <div className='UserInfo'>
      <Avatar avatarUrl={props.author.avatarUr} name={props.author.name} />
      <UserInfoName name={props.author.name} />
    </div>
  );
}

function CommentText(props){
  return (
    <div className='Comment-text'>
      {props.text}
    </div>
  );
}

function CommentDate(props){
  return (
    <div className='Comment-date'>
      {props.date}
    </div>
  );
}

function Comment(props){
  
  return (
    <div className='Comment'>
      <UserInfo author={props.cmt.author}/>
      <CommentText text={props.cmt.text}/>
      <CommentDate date={props.cmt.date}/>
    </div>
  );
}

class Clock extends React.Component{
  constructor(props) {
    super(props);
    this.state = {date: new Date()};
  }

  componentDidMount(){
    this.timeIntervalID = setInterval(()=>{
      this.setState({
        date: new Date()
      });
    },1000);
  }

  componentWillUnmount(){
    clearInterval(this.timeIntervalID);
  }

  render(){
    return (
      <div>
        <p>hello, {this.props.name}!</p>
        <p>now time is {this.state.date.toLocaleTimeString()}</p>
      </div>
    );
  }
}


class MyButton extends React.Component {
  constructor(props) {
    super(props);
    this.state = {btnOn: false};
    this.handle = this.handle.bind(this);
  }

  handle(id){
    this.setState((prevState) => ({
      btnOn: !prevState.btnOn
    }), () => {
      const p = document.createElement('p');
      let text = !this.state.btnOn ? "开关已关闭" : "开关已开启";
      p.textContent =  text + id;
      document.body.appendChild(p);
    });
  }

  render(){
    return(
      // <button onClick={this.handle.bind(this, "111")}>
      //   {this.state.btnOn ? "关闭" : "开启"}
      // </button>

      <button onClick={(e) => this.handle("111", e)}>
        {this.state.btnOn ? "关闭" : "开启"}
      </button>
    );
  }
}

class List extends React.Component {
  constructor(props) {
    super(props);
  }
  render(){
    const list = this.props.list;
    const listItems = list.map((item)=>
      <li>这是第{item}行</li>
    );
    return (
      <ul>
        {list.map(item => {
           return <li key={item.toString()}>这是第{item}行</li>
          }
        )}
      </ul>
    );
  }
}

class MyForm extends React.Component {
  constructor(props){
    super(props);

    this.handleValueChange = this.handleValueChange.bind(this);
    this.handleSubmit = this.handleSubmit.bind(this);
    this.handleTextChange = this.handleTextChange.bind(this);
    this.handleSelectChange = this.handleSelectChange.bind(this);

    this.state = {
      name:"",
      placeholder:"请输入姓名",
      text:"请撰写一篇关于你喜欢的 DOM 元素的文章.",
      select:"pingguo"
    };
  }

  handleValueChange(event) {
    this.setState({name: event.target.value});
  }
  
  handleTextChange(event) {
    this.setState({text: event.target.value});
  }

  handleSelectChange(event) {
    this.setState({select: event.target.value});
  }

  handleSubmit(event){
    console.log("提交的名字" + this.state.name);
    event.preventDefault();
  }

  render(){
    return (
      <form onSubmit={this.handleSubmit}>
        <label>
          名字：
          <input type="text" value={this.state.name} placeholder={this.state.placeholder} onChange={this.handleValueChange}/>
        </label>
        <br/>
        <label>
          文章：
          <textarea value={this.state.text} onChange={this.handleTextChange} />
        </label>
        <br/>
        <label>
          选择口味：
          <select value={this.state.select} onChange={this.handleSelectChange}>
            <option value="putao">葡萄</option>
            <option value="pingguo">苹果</option>
            <option value="li">梨</option>
          </select>
        </label>
        <br/>
        <input type="submit" value="提交"/>
      </form>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
// const element = <h1>你好，陌生人！</h1>
const cmt = {
  "author":{
    "avatarUr":"https://www.jd.com/aaaa/bbb.png",
    "name":"wallace"
  },
  "text":"it is very beatiful",
  "date":"2022-12-1"
};
const element = (
  <div>
    <h1>Hello, world!</h1>
    <p>大家好！dd</p>
    <Comment cmt={cmt}/>
    <Clock name="wallace"/>
    <MyButton/>
    <List list={[1,2,3,4,5]}/>
    <MyForm/>
  </div>
);
root.render(
  // <React.StrictMode>
  //   <App />
  // </React.StrictMode>
//   <div>
// <h1>Hello, world!</h1>
//   <p>大家好！</p>
//   </div>
  element
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
