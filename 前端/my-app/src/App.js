import { Button } from 'antd';
import logo from './logo.svg';
import './App.css';
import React from 'react';

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

class  ThemedButton extends React.Component {
  // static contextType = TypeContext;
  
  render() {
    const {type,toggleBtn} = this.context;
    return (
      <div>
        <Button type={type}>button1</Button>
        <Button type={type}>button2</Button>
        <Button type={type} onClick={toggleBtn}>button3</Button>
      </div>
    )
  }
}

ThemedButton.contextType = TypeContext;

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
      <TypeContext.Provider value={this.state}>
        <ToolBar />
      </TypeContext.Provider>
    );
  }
}

