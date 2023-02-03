import React from "react";
import { Switch , Route} from "react-router-dom"
import { navs } from "../routers/navs";

export default () => {
    return (
        <div>
            {/* <Headers /> */}
            <div>
                <Switch>
                    {/* <Routers /> */}
                    {navs.map((item) => {
                        console.log(item.path);
                        <Route path={item.path} key={item.key} component={item.component}></Route>
                    })}
                </Switch>
            </div>
        </div>
    );
};