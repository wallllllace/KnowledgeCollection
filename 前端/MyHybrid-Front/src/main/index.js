import React from "react";
import { Switch, useHistory } from "react-router-dom"
import { Route, useLocation } from "react-router";
import { navs } from "../routers/navs";
import Header from "../components/header";
import "./style.scss"

export default () => {
    const history = useHistory();
    const location = useLocation();
    
    React.useEffect(() => {
        console.log("aaa" + location.pathname);
    }, [location]);

    return (
        <div className="main-container">
            <Header />
            <div className="main-container-content">
                <Switch>
                    {/* <Routers /> */}
                    {navs.map((item) => (
                         <Route exact={item.key === "main"} path={item.path} key={item.key} component={item.component} />
                    ))}
                </Switch>
            </div>
        </div>
    );
};