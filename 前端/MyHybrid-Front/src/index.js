import React from 'react'
import ReactDOM from 'react-dom'
// import App from './App'
import { BrowserRouter, Switch, Route, Link } from "react-router-dom"
import { Provider } from 'mobx-react';
import store from './stores/index';
import Main from './main/index'

ReactDOM.render(
    <Provider {...store}>
        <BrowserRouter>
            {/* <nav>
                <ul>
                    <li><Link to="/home">Home</Link></li>
                    <li><Link to="/about">About</Link></li>
                    <li><Link to="/me">Me</Link></li>
                    <li><Link to="/other">Other</Link></li>
                </ul>
            </nav>
            <Switch>
                <Route path="/home">
                    <Home />
                </Route>
                <Route path="/about">
                    <About />
                </Route>
                <Route path="/me">
                    <Me />
                </Route>
                <Route path="/other">
                    <Other />
                </Route>
            </Switch> */}
            <Main />
        </BrowserRouter>
    </Provider>
    , document.getElementById('app'));