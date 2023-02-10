import React from "react";
import "./style.scss";
import Header from "./header";
import Advantage from "./advantage";

export default () => {
    return (
        <div className="home-container">
            <div className="home-header-container">
                <Header />
            </div>
            <div className="home-advantage-container">
                <Advantage />
            </div>
            <div className="home-ability-container">

            </div>
            <div className="home-stats-container">

            </div>
            <div className="home-example-container">

            </div>
            <div className="home-app-container">

            </div>
            <div className="home-contact-container">

            </div>
            
            
        </div>
    );
};