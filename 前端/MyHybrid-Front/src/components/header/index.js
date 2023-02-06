import React, { useState } from "react";
import { observer } from "mobx-react-lite";
import { useHistory } from "react-router-dom";
import "./style.scss";
import { navs } from "../../routers/navs";

const Header = () => {
    const history = useHistory();
    const [focus, setFocus] = useState("main");

    const clickNavTab = (e, item) => {
        setFocus(item.key);
        history.push(item.path);
    };

    const Tabs = () => {
        return (
            <>
            {
                navs.map((item) => (
                    <div key={item.key} 
                    className={`header-router-navlink ${focus === item.key && 'nav-active'}`}
                    onClick={(e) => {clickNavTab(e, item)}}>
                        <span className="header-text">{item.name}</span>
                    </div>
                ))
            }
            </>
        );
    };

    return (
        <div>
            <div className="header">
                <div className="header-router-container">
                    <Tabs/>
                </div>
            </div>
            <div className="header-placement"></div>
        </div>
        
        
    );
    
};

export default observer(Header);