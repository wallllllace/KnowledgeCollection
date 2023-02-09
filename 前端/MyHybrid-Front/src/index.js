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
            <Main />
        </HashRouter>
    </Provider>
    , document.getElementById('app'));