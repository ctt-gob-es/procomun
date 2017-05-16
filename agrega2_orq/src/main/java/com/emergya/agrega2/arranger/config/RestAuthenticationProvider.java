package com.emergya.agrega2.arranger.config;

import java.util.ArrayList;
import java.util.List;

import org.springframework.security.authentication.AuthenticationProvider;
import org.springframework.security.authentication.AuthenticationServiceException;
import org.springframework.security.authentication.BadCredentialsException;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.authentication.dao.AbstractUserDetailsAuthenticationProvider;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.util.Assert;

import com.emergya.agrega2.arranger.util.impl.Utils;

public class RestAuthenticationProvider extends AbstractUserDetailsAuthenticationProvider implements
        AuthenticationProvider {

    public Authentication authenticate(Authentication authentication) {
        Assert.isInstanceOf(UsernamePasswordAuthenticationToken.class, authentication,
                "Only UsernamePasswordAuthenticationToken is supported");

        // Determine username
        String username = authentication.getName();

        UserDetails user = null;

        try {
            user = retrieveUser(username, (UsernamePasswordAuthenticationToken) authentication);
        } catch (UsernameNotFoundException notFound) {
            throw new BadCredentialsException("Bad credentials");
        }

        Assert.notNull(user, "retrieveUser returned null - a violation of the interface contract");

        return createSuccessAuthentication(user, authentication, user);
    }

    @Override
    protected void additionalAuthenticationChecks(UserDetails arg0, UsernamePasswordAuthenticationToken arg1) {
        // TODO: En principio no hay que comprobar nada más en este punto
    }

    @Override
    protected UserDetails retrieveUser(String username, UsernamePasswordAuthenticationToken authentication) {
        UserDetails loadedUser;

        String presentedPassword = authentication.getCredentials().toString();

        loadedUser = checkUser(username, presentedPassword);

        if (loadedUser == null) {
            throw new AuthenticationServiceException("User not valid");
        }

        return loadedUser;
    }

    private UserDetails checkUser(String username, String password) {
        UserDetails user = null;

        String[] roles = check(username, password);
        if (roles.length > 0) {
            final List<GrantedAuthority> auths = new ArrayList<GrantedAuthority>();
            for (String rol : roles) {
                auths.add(new SimpleGrantedAuthority(rol));
            }
            user = new User(username, password, auths);
        }

        return user;

    }

    private String[] check(String username, String password) {
        if (Utils.getToken(Long.parseLong(username)).equals(password)) {
            return new String[] { "APP" };
        } else {
            return new String[] {};
        }
    }
}
