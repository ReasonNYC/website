import React from 'react';
import Route from 'react-router-dom/Route';
import Switch from 'react-router-dom/Switch';

function App({ routes }) {
  return (
    <div>
      <Switch>
        {routes.map(route => (
          <Route
            key={route.path}
            render={props => <route.component />}
            path={route.path}
            exact={true}
          />
        ))}
      </Switch>
    </div>
  );
}

export default App;
