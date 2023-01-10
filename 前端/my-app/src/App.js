import { Button } from 'antd';
import logo from './logo.svg';
import './App.css';
import React from 'react';
import { useState } from 'react';
import { useEffect } from 'react';
import { useContext } from 'react';

const TypeContext = React.createContext({
    type: 'link',
    toggleBtn: () => {}
});

function App() {
  return (
    <div className="App">
      {/* <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header> */}
      {/* <TypeContext.Provider value='link'>
        <ToolBar />
      </TypeContext.Provider> */}
      
      <ThemeBox />
    </div>
  );
}

export default App;

function ToolBar(props){
  return (
    <div>
      <ThemedButton />
    </div>
  );
}

// class  ThemedButton extends React.Component {
//   // static contextType = TypeContext; 
  
//   render() {
//     // const {type,toggleBtn} = this.context;
//     const {type,toggleBtn} = useContext(TypeContext);
//     return (
//       <div>
//         <Button type={type}>button1</Button>
//         <Button type={type}>button2</Button>
//         <Button type={type} onClick={toggleBtn}>button3</Button>
//       </div>
//     )
//   }
// }

// ThemedButton.contextType = TypeContext;


function  ThemedButton() {
  const {type,toggleBtn} = useContext(TypeContext);
  return (
    <div>
      <Button type={type}>button1</Button>
      <Button type={type}>button2</Button>
      <Button type={type} onClick={toggleBtn}>button3</Button>
    </div>
  );
}

class ThemeBox extends React.Component {
  constructor(props) {
    super(props);
    this.toggleBtn = this.toggleBtn.bind(this);

    this.state = {
      type: "dashed",
      toggleBtn: this.toggleBtn
    };
  }

  toggleBtn() {
    console.log("clicked");
    this.setState(prevState => {
      console.log(prevState);
      return {
        type: prevState.type === 'dashed' ? 'primary' : 'dashed'
      };
    });
  }

  render(){
    return (
      <div>
        <TypeContext.Provider value={this.state}>
        <ToolBar />
        </TypeContext.Provider>
        <CustomTextInput />
        <AutoFocusTextInput />
        <WelcomeDialog />
        <Clock />
      </div>
    );
  }
}

/*
class CustomTextInput extends React.Component {
  constructor(props) {
    super(props);

    this.textInput = React.createRef();
    this.focusTextInput = this.focusTextInput.bind(this);
  }

  focusTextInput() {
    this.textInput.current.focus();
  }

  render() {
    return (
      <div>
        <input type="text" ref={this.textInput}/>
        <input type="button" value="Focus the text input" onClick={this.focusTextInput}/>
      </div>
    );
  }
}
*/

// ref传递一个函数
class CustomTextInput extends React.Component {
  constructor(props) {
    super(props);

    this.textInput = null;
    this.setTextInputRef = element => {
      this.textInput = element;
    };
    this.focusTextInput = () => {
      if(this.textInput) this.textInput.focus();
    };
  }

  componentDidMount() {
    this.focusTextInput();
  }

  render() {
    return (
      <div>
        <input type="text" ref={this.setTextInputRef} />
        <input type="button" value="Focus the text input" onClick={this.focusTextInput}/>
      </div>
    );
  }
}

class AutoFocusTextInput extends React.Component {
  constructor(props) {
    super(props);
    this.textInput = React.createRef();
  }

  componentDidMount(){
    this.textInput.current.focusTextInput();
  }

  render() {
    return (
      <CustomTextInput ref={this.textInput}/>
    );
  }
}

class FancyBorder extends React.Component {
  constructor(props) {
    super(props);
  }
  render() {
    return (
      <div>
        <p>下面是left</p>
        {this.props.left}
        <p>下面是right</p>
        {this.props.right}
        <p>下面是children</p>
        {this.props.children}
      </div>
    );
  }
}

class WelcomeDialog extends React.Component {
  constructor(props) {
    super(props);
  }
  render() {
    return (
      <FancyBorder left={
        <p>我是left</p>
      } right={
        <p>我是right</p>
      }>
        <h1>Welcome</h1>
        <p>Thank you for visiting our spacecraft!</p>
      </FancyBorder>
    );
  }
}

function Clock() {
  const [count, setCount] = useState(0);

  useEffect(() => {
    document.title = `You click ${count} times`;
  });

  return (
    <div>
      <p>You click {count} times</p>
      <button onClick={() => setCount(count+1)}>
        Click me
      </button>
    </div>
  );
}

