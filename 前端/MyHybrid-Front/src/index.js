import React from 'react'
import ReactDOM from 'react-dom'
// import App from './App'
import { BrowserRouter, Switch, Route, Link, HashRouter, useHistory } from "react-router-dom"
import { Provider } from 'mobx-react';
import store from './stores/index';
import Main from './main/index'

// const history = useHistory();

ReactDOM.render(
    <Provider {...store}>
        <HashRouter>
            {/* <nav>
                <ul>
                    <li><Link to="/home">Home</Link></li>
                    <li><Link to="/projects">Projects</Link></li>
                    <li><Link to="/dataCenter">DataCenter</Link></li>
                    <li><Link to="/document">Document</Link></li>
                    <li><Link to="/xconsole">Xconsole</Link></li>
                    <li><Link to="/admin">Admin</Link></li>
                </ul>
            </nav> */}
            <Main />
        </HashRouter>
    </Provider>
    , document.getElementById('app'));